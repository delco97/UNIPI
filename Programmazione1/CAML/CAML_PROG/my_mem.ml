let rec my_mem l n = match l with
	  [] -> false
	| [x] -> x = n
	| y::(x::xs) -> if y = n then true
 			else my_mem (x::xs) n;;

my_mem [] 2;;
my_mem [2] 2;; 
my_mem [1;1;1;1;1;2] 2;; 
my_mem [1;2;1] 2;;
