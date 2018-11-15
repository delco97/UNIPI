let lenght lis = 
	let rec f lis cont = match lis with
	    [] -> cont
	  | x::xs -> f xs (cont + 1)
	in f lis 0;;
	
let cancella n l = 
  let start = (lenght l) - n
  in
  let rec f n l i = match l with
	  [] -> []
	| x::xs -> if i > start then f n xs (i+1)  
		   else x::(f n xs (i+1))
  in f n l 1;;
  
cancella 2 [1;2;3;4];;   
