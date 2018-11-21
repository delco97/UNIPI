let p x = x mod 2 = 0;;
let rec forall l p = match l with
	  [] -> true
	| x::xs -> if (p x) = false then false
                   else forall xs p;;

forall [] p = true;;
forall [1] p = false;;
forall [0;2;4;6;8] p = true;;
