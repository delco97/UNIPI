let rec foldr f a l = match l with
	  [] -> a
	| x::xs -> f x (foldr f a xs);;

let somma x y = x + y
in foldr somma 0 [1;2;3];;

let prod x y = x * y
in foldr prod 1 [1;2;5];;
