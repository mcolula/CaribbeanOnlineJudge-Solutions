def sum(a, b)
  return 2 * a + 2 * b
end

a, b = gets.chomp.split(" ")
a = Integer(a)
b = Integer(b)

puts sum(a, b)
