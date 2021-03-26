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

type Factory interface {
	CreateFruit() Fruit
}
type AppleFactory struct {
}

func (this *AppleFactory) CreateFruit() Fruit {
	return &Apple{}
}

type BananaFactory struct {
}

func (this *BananaFactory) CreateFruit() Fruit {
	return &Banana{}
}
