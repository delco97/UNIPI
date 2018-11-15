let rec filter p l = match l with
	  [] -> []
	| x::xs -> if p x then filter p xs 
		   else x::(filter p xs);; 

let solo_pos l =
	let pos a = a >= 0
	in filter pos l;;

solo_pos [-1;1;-1;0];;


