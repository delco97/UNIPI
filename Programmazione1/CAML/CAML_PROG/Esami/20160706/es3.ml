let mf lis =
  let f x m = if x < m then x else m
  in
  let min = match lis with
    []->0 |
    w::ws -> foldr f w lis
  in
  let g y ris = if y = min then y::ris else ris @ [y]
  in
  foldr g [] lis;;

mf [2;2;1];;
