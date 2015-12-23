def swap_all(s, a)  
  m = a.map { |a| s + a }
  p = Array.new
  for w in m do 
    p = p + swap(w)
  end
  p
end

def swap(w)
  n = w.size
  p = Array.new
  for i in 0..(n - 1) do
    a = String.new(w)
    a[0], a[i] = a[i], a[0]
    p.push(a)
  end
  p
end
  
def permutation(s, n)
  return [s] if n < 2
  return swap_all(s[0], permutation(s[1..n], n - 1))
end
test = Integer(gets.chomp)
test.times {
  i = Integer(gets.chomp)
  s = (1..i).inject("") {|a, b| a + b.to_s}
  p = permutation(s, i).sort
  puts p[p.size / 3]
}
