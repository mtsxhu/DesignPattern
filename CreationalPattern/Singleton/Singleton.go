package signal

import "sync"

/*饿汉*/
type hungry struct {
}

var hungryInstance *hungry = &hungry{}

/*懒汉*/
type lazy struct {
}

var lazyInstance *lazy = nil

func GetLazyInstance() *lazy {
	if lazyInstance == nil {
		lazyInstance = &lazy{}
	}

	return lazyInstance
}

/*线程安全的懒汉*/
type safeLazy struct {
}

var safeLazyInstance *safeLazy
var m sync.Mutex

func GetSafeLazyInstance() *safeLazy {
	if safeLazyInstance == nil {
		m.Lock()
		if safeLazyInstance == nil {
			safeLazyInstance = &safeLazy{}
		}
		m.Unlock()
	}
	return safeLazyInstance
}

/*线程安全的单例02*/
type safeLazy02 struct {
}

var safeLazy02Instance *safeLazy02 = nil

// sync.Once的Do方法保证在程序运行时只调用一次
var o sync.Once

func GetSafeLazyInstance02() *safeLazy02 {
	o.Do(func() {
		safeLazy02Instance = &safeLazy02{}
	})
	return safeLazy02Instance
}
