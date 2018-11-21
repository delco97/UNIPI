let palindroma l =
	let rec inv l1 = match l1 with
		  [] -> []
		| x::xs -> inv xs @ [x]
	in
	l = inv l;;

palindroma [];;
palindroma [1];;
palindroma [1;2];;
palindroma [1;2;1];;
