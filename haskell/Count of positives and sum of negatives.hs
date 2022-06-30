module Kata where
import Data.Maybe (fromMaybe)

countPositives = length . filter (> 0)
sumNegatives = sum . filter (< 0)

countPositivesSumNegatives :: Maybe [Int] -> [Int]
countPositivesSumNegatives xs
  | not (null s) = [countPositives s, sumNegatives s]
  | otherwise = []
  where s = filter (/= 0) (fromMaybe [] xs)