module Codewars.Kata.FakeBinary where

replace :: Char -> Char
replace x
  | x < '5' = '0'
  | otherwise = '1'

fakeBin :: String -> String
fakeBin xs = map replace xs