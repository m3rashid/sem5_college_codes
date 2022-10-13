package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
)

const (
	SERVER_HOST = "localhost"
	SERVER_PORT = "9988"
	SERVER_TYPE = "tcp"
)

func main() {
	connection, err := net.Dial(SERVER_TYPE, SERVER_HOST+":"+SERVER_PORT)
	if err != nil {
		panic(err)
	}

	for {
		fmt.Print("Enter Text: ")
		reader := bufio.NewReader(os.Stdin)
		text, err := reader.ReadString('\n')
		if err != nil {
			log.Fatal(err)
		}

		_, err = connection.Write([]byte(text))
		if err != nil {
			log.Fatal(err)
			continue
		}

		buffer := make([]byte, 1024)
		mLen, err := connection.Read(buffer)
		if err != nil {
			fmt.Println("Error reading:", err.Error())
			// continue
		} else {
			fmt.Println("Received: ", string(buffer[:mLen]))
		}
		// defer connection.Close()
	}
}
