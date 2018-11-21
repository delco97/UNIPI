let rec foldr f a l = match l with
	  [] -> a
	| x::xs -> f x (foldr f a xs);;

let max_positivi l = 
   let f a b = if a > b then a
	       else b
   in foldr f (-1) l;;

max_positivi [0;5;3;2;10;34;2;2];;

let max l = 
   let f a b = if a > b then a
	       else b
   in match l with
        | x::xs -> foldr f x l;;

max [0;1;-1;-10;5];;

