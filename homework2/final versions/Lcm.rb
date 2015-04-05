class Lcm



def gcd(x, y)
  return y == 0 ? x : gcd(y, x % y)
end

def lcm(x,y)
	return (x*y)/gcd(x,y)
end

# for quick testing purposes
 # x = Lcm.new
 # puts "hi"
 # puts "gcd(2,3): "
 # puts "gcd(2,3):  #{x.gcd(2,3)}."
 # puts "lcm(12,18):  #{x.lcm(12,18)}."


end