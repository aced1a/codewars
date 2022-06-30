module Initials where
import Data.Char

split :: [Char] -> ([Char], [Char])
split s = break (' ' == ) s
        
getInitials :: String -> String
getInitials s = [toUpper (head first)] ++ "." ++ [toUpper (head rest)]
        where (first, second) = split s
              (_, rest) = span (== ' ') second