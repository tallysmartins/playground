defmodule ChampionChipBestScore do
  def play do
    teams = create_teams()
    matches = create_matches()

    matches
    |> calculate_host_points
    |> calculate_visitor_points
    |> count_teams_points(teams)
    |> sum_total_score_points
    |> get_winner
    |> display_results
  end

  defp create_teams do
    [
      %{id: 1, name: 'Raptors'},
      %{id: 2, name: 'Warriors'}
    ]
  end

  defp create_matches do
    [
      %{host_id: 1, visitor_id: 2, host_score: 0, visitor_score: 0},
      %{host_id: 2, visitor_id: 1, host_score: 0, visitor_score: 3},
      %{host_id: 1, visitor_id: 2, host_score: 2, visitor_score: 0},
      %{host_id: 2, visitor_id: 1, host_score: 2, visitor_score: 2}
    ]
  end

  # Add an entry with the points scored by the host in each match
  # %{host_id: 2, visitor_id: 1, host_score: 2, visitor_score: 2, host_points: 1}
  defp calculate_host_points(matches) when is_list(matches) do
    matches
    |> Enum.map(fn match -> calculate_host_points(match) end)
  end
  defp calculate_host_points(match) when is_map(match) do
    match
    |> Map.put(:host_points, calculate_host_points(Map.get(match, :host_score), Map.get(match, :visitor_score)))
  end
  defp calculate_host_points(host_score, visitor_score) do
    balance_score = host_score - visitor_score

    cond do
      balance_score == 0 -> 1
      balance_score > 0 -> 3
      balance_score < 0 -> 0
    end
  end

  # Add an entry with the points scored by the visitor in each match
  # %{host_id: 2, visitor_id: 1, host_score: 2, visitor_score: 2, visitor_points: 1}
  defp calculate_visitor_points(matches) when is_list(matches) do
    matches
    |> Enum.map(fn match -> calculate_visitor_points(match) end)
  end
  defp calculate_visitor_points(match) when is_map(match) do
    match
    |> Map.put(:visitor_points, calculate_visitor_points(Map.get(match, :host_score), Map.get(match, :visitor_score)))
  end
  defp calculate_visitor_points(host_score, visitor_score) do
    balance_score = visitor_score - host_score

    cond do
      balance_score == 0 -> 1
      balance_score > 0 -> 3
      balance_score < 0 -> 0
    end
  end

	# For each team, aggregate its host and visitor points over the matches it
	# has participated
  defp count_teams_points(matches, teams) when is_list(teams) do
    teams
    |> Enum.map(fn team -> count_host_points_per_team(matches, team) end)
    |> Enum.map(fn team -> count_visitor_points_per_team(matches, team) end)
  end

  defp count_host_points_per_team(matches, team) when is_map(team) do
    %{id: id} = team

    host_points =
      matches
      |> Enum.group_by(fn x -> Map.get(x, :host_id) end, fn x -> Map.get(x, :host_points) end)
      |> Map.get(id)
      |> Enum.sum

    Map.put(team, :host_points, host_points)
  end

  defp count_visitor_points_per_team(matches, team) when is_map(team) do
    %{id: id} = team

    visitor_points =
      matches
      |> Enum.group_by(fn x -> Map.get(x, :visitor_id) end, fn x -> Map.get(x, :visitor_points) end)
      |> Map.get(id)
      |> Enum.sum

    Map.put(team, :visitor_points, visitor_points)
  end

  defp sum_total_score_points(teams_table) do
    teams_table
    |> Enum.map(fn team -> Map.put(team, :total_points, Map.get(team, :visitor_points) + Map.get(team, :host_points)) end)
  end

  defp get_winner(teams_table) do
    teams_table
    |> Enum.max_by(fn team -> Map.get(team, :total_points) end)
  end

  defp display_results(team) do
    %{name: name, total_points: total_points} = team

    IO.puts("\n#################################################")
    IO.puts("  The WINNER are the #{name}! Congratulations!")
    IO.puts("  They have scored #{total_points} points in the tournament!")
    IO.puts("#################################################\n")
  end
end

ChampionChipBestScore.play()
