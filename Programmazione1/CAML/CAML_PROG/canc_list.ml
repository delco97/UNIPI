let rec canc l el = match l with
	  [] -> []
	| [x] -> if x = el then [] else [x]
	| x::(y::ys) ->  if x = el then y::ys
			 else x::(canc (y::ys) el);;

canc [] 2;;
canc [2] 2;;
canc [2] 1;;
canc [3;3] 3;;
canc [2;3;2] 3;;
canc [2;2;2;2;3] 3;;
canc [2;2;2;2] 0;;
