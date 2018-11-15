let rec my_combine l1 l2 = match (l1,l2) with
	  ([],[]) -> []
	| (x::xs,[]) -> []
	| ([],x::xs) -> []
	| (x::xs, y::ys) -> (x,y)::(my_combine xs ys);;

my_combine  ["a";"b";"c"] [1;2;3];;

