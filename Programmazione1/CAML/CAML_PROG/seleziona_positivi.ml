let rec filter p l = match l with
	  [] -> []
	| x::xs -> if p x then filter p xs 
		   else x::(filter p xs);; 

let negativo x = x<0
in filter negativo [-1;1;-1;1;0];;



