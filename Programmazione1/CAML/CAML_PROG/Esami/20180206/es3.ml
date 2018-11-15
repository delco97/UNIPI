let zerouno l =
	let rec f l a b = match l with
	    [] -> a = b
          | x::xs when x<>0 & x<>1 -> false
	  | x::xs when x=0 -> f xs (a+1) b
	  | x::xs when x=1 -> f xs a (b+1)
	in f l 0 0;;


zerouno [1;0;1;1];;
