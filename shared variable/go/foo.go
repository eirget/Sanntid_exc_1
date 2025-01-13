// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
)

var i = 0

func incrementing(req chan string, done chan bool) {
	for j := 0; j < 999999; j++ {
		req <- "increment"
	}
	done <- true
}

func decrementing(req chan string, done chan bool) {
	for j := 0; j < 1000000; j++ {
		req <- "decrement"
	}
	done <- true
}

func server(req chan string, resp chan int) {
	for {
		select {
		case value := <-req:
			switch value {
			case "increment":
				i++
			case "decrement":
				i--
			case "get":
				resp <- i
			}
		}
	}
}

func main() {
	// What does GOMAXPROCS do? What happens if you set it to 1?
	runtime.GOMAXPROCS(2)

	req := make(chan string)
	resp := make(chan int)
	done := make(chan bool)

	// TODO: Spawn both functions as goroutines

	go server(req, resp)
	go decrementing(req, done)
	go incrementing(req, done)

	<-done
	<-done

	req <- "get"
	finalValue := <-resp
	Println("The magic number is:", finalValue)
}
