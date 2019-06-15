defmodule Puzzle do

  @moduledoc """
    This module allows you to play the Suzan Puzzle. The Puzzle is about
    walking up and down the floors of a building. There are two commands that
    makes Suzan walk, '(' to go up and ')' to go down. The Puzzle gets a series
    of commands given from the terminal and then process the information to
    give the final position of Suzan after following the sequence of commands.
  """

  def play do
    read_instructions()
    |> walk()
    |> output()
  end

  defp read_instructions do
    IO.gets('[I] Type the instructions e.g. (()())\n')
    |> String.trim
  end

  defp walk([], floor), do: floor 

  defp walk(["(" | t], floor) do
    walk(t, floor + 1)
  end

  defp walk([")" | t], floor) do
    walk(t, floor - 1)
  end

  defp walk([h | t], floor) do
    IO.puts('[E] Undefined instruction #{h}')
    IO.puts('[E] Refer to the docs of available instructions')
    walk(t, floor)
  end

  def walk(instructions) do
    String.codepoints(instructions)
    |> walk(0)
  end

  defp output(floor) do
    IO.puts('[I] The current floor is #{floor}')
  end
end

Puzzle.play
