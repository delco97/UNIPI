let len l = 
	let rec f l dim = match l with
	     [] -> dim
	   | x::xs -> f xs (dim +1)
	in f l 0;;

len [];;
len[1];;
len[1;1];;

