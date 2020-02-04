p:[ws = &b - &a] 
  parse((decimal(ws) = {<Word size: > 1 * }))
  [x = &b]
  [y = *x]
  [x = *(((&a)+2)-2)]
  parse((decimal(x) decimal(y)
         = {<b=> 1 <, a=> 2 * }));
a:1; b: 2; ws: 0; x: 0; y: 0;
