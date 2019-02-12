Drazil = sum([int("1") if x=="+" else int("-1") for x in list(input())])
Dreamoon = [int("1") if x=="+" else int("-1") if x=="-" else x for x in list(input())]
num = Dreamoon.count("?")
if(num == 0):
  temp = sum(Dreamoon)
  if(temp == Drazil):
    print("%.12f" % (temp/Drazil))
  else:
    print("%.12f" % (0))
else:
  sum_ = 0
  for x in Dreamoon:
    if(x != "?"):
      sum_+=x

  dist = Drazil - sum_
  if((dist+num)%2!=0 or num<abs(dist)):
    print("%.12f" % (0))
  else:
     m = (num+abs(dist))//2
     c = 1
     for i in range(m):
       c *= num-i
     for i in range(2,m+1):
       c /= i
     answer = c/(2**num)
     print("%.12f" % (answer))


