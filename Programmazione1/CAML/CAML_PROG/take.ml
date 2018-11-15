let rec take n l = match (n,l) with
	  (n,l) when n<=0 -> []
	| (n,[]) when n>0 -> []
        | (n,x::xs) when n>0 -> x::(take (n-1) xs);;

take 2 [1;2];;
