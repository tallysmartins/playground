defmodule FizzBuzz do
	def up_to(n) do
		1..n
		|> Enum.map(&fizzbuzz/1)
		|> Enum.map(&IO.inspect/1)
	end

	defp fizzbuzz(n) do
		fizzbuzz(n, rem(n, 3), rem(n, 5))
	end

	defp fizzbuzz(_n, 0, 0), do: "FizzBuzz"
	defp fizzbuzz(_n, 0, _), do: "Fizz"
	defp fizzbuzz(_n, _, 0), do: "Buzz"
	defp fizzbuzz(n, _, _), do: n
end

FizzBuzz.up_to(30)
