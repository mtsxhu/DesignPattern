package main

import "fmt"

type Fruit interface {
	GetName()
}
type Apple struct {
}

func (this *Apple) GetName() {
	fmt.Println("苹果")
}

type Banana struct {
}

func (this *Banana) GetName() {
	fmt.Println("香蕉")
}

type Factory struct {
}

func (this *Factory) CreateFruit(fruit string) Fruit {
	switch fruit {
	case "苹果":
		return &Apple{}
	case "香蕉":
		return &Banana{}
	}
	return nil
}
