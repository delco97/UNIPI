let intersezione l1 l2 = 
  let rec member l a = match l with
	  [] -> false
	| x::xs -> if x=a then true else member xs a
  in
  let rec aux_intersezione r1 r2 r = match r1 with
	  [] -> r
	| w::ws-> if ((member r2 w) & (member r w)=false) then aux_intersezione ws r2 (w::r)
		  else aux_intersezione ws r2 r
  in
  aux_intersezione l1 l2 [];;

intersezione [] [];;
intersezione [] [1];;
intersezione [1] [];;
intersezione [1;1] [1];;
intersezione [1;1;2] [1;2];;
