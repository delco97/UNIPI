let rec split lis = match lis with
	| []->([],[])
	| (x,y)::xs -> let (l1,l2) = 
          		    split xs
		       in (x::l1,y::l2);;

split [(1,"a");(2,"b");(3,"c")];;

