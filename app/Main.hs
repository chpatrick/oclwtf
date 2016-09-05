module Main where

foreign import ccall safe "OpenCL.h listPlatforms" listPlatforms :: IO ()

main :: IO ()
main = listPlatforms
