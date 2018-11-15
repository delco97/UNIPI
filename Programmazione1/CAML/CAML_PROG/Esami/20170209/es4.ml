let avg lis = match lis with
	x::xs -> let f a (sum,count) = (sum+a,count+1)
		 in
		 let (s,c) = foldr f (0,0) lis
		 in
		 s/c;;

avg [10;5;10];;
