module TotalPoints where

count xs
  | x > y  = 3
  | x == y = 1
  | otherwise = 0
  where (x, _:y) = break (':' == ) xs

points :: [String] -> Int
points = sum . map count