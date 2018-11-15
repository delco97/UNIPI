let rec steps n = 
	if (n < 0) then 0 
	else 
	    if (n=0) then 1
	    else steps (n-1) + steps (n-2);;

steps 9;;
