let nth list el = 
  let f l n pos = match l with
	   [] -> -1 
         | [x] -> if x = n then pos else -1
         | y::x::xs -> if y = n then pos
                                else f (x::xs) n (pos+1)
  in f list el 1;;

nth [3;4] 4;;
