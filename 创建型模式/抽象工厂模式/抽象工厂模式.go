package main

import "fmt"

type Appler interface {
	GetAppleName()
}
type Bananaer interface {
	GetBananaName()
}
type ChinaApple struct {
}

func (this *ChinaApple) GetAppleName() {
	fmt.Println("中国苹果")
}

type ChinaBanana struct {
}

func (this *ChinaBanana) GetBananaName() {
	fmt.Println("中国香蕉")
}

type USAApple struct {
}

func (this *USAApple) GetAppleName() {
	fmt.Println("美国苹果")
}

type USABanana struct {
}

func (this *USABanana) GetBananaName() {
	fmt.Println("美国香蕉")
}

type Factory interface {
	CreateApple() Appler
	CreateBanana() Bananaer
}
type ChinaFactory struct {
}

func (this *ChinaFactory) CreateApple() Appler {
	return &ChinaApple{}
}
func (this *ChinaFactory) CreateBanana() Bananaer {
	return &ChinaBanana{}
}

type BananaFactory struct {
}

func (this *BananaFactory) CreateApple() Appler {
	return &USAApple{}
}
func (this *BananaFactory) CreateBanana() Bananaer {
	return &USABanana{}
}
