module Kata (past) where

past :: Int -> Int -> Int -> Int
past h m s = (h * 3600 + m * 60 + s) * 1000