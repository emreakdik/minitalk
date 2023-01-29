# minitalk
Communication between two programs using signals

### PID (Process Identification)

PID, süreç kimliği (Process Identification) bir süreç için benzersiz bir numaradır. Bu numara, sistem üzerinde çalışan her süreç için benzersiz olarak atanır ve sistem tarafından kullanılır. PID, süreçleri tanımlamak, izlemek ve yönetmek için kullanılır. Örneğin, bir süreci durdurmak veya yeniden başlatmak için PID kullanılır. Ayrıca, bir sürecin çalışma durumunu izlemek için de PID kullanılır. 

> *Burada surecten kasit programdir.*
> *PID 5 hanelidir.*

# Kullanilan Fonksiyonlar

### getpid()
C dilinde getpid fonksiyonu, sistem üzerinde çalışan bir sürecin benzersiz kimlik numarasını (PID) döndürür. Bu fonksiyon, sistem çağrısı olarak gerçekleştirilir ve çalışan sürecin PID'sini döndürür. getpid() fonksiyonu, *<unistd.h>* kütüphanesinde tanımlıdır. Bu fonksiyon sadece UNIX ve benzeri işletim sistemlerinde geçerlidir.

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    int pid = getpid();
    printf("Current process id: %d\n", pid);
    return 0;
}
```

### kill()
Bu fonksiyon,  herhangi bir islem veya islem grubuna sinyal gondermek icin kullanilir.

- Eger return eden deger, pozitif ise sinyal gonderilmis anlamina gelir.
- Eger return -1 ise sinyal gonderiminde hata gerceklesmis anlamina gelir. 
 
 ```c
 #include <sys/signal.h>

int main() {
    int pid = 123;
    int signal_number = SIGTERM;
    int result = kill(pid, signal_number);
    if (result == -1) {
        perror("Error sending signal");
    }
    return 0;
}
 ```


### signal()

Bu fonksiyon sinyal olaylarını işlemek için kullanılabilir. Örneğin, bir programda belirli bir sinyal gerçekleştiğinde belirli bir işlem yapmak isteyebilirsiniz ve bu durumda signal() fonksiyonunu kullanabilirsiniz. Bu fonksiyon, sinyal gerçekleştiğinde çağırılacak olan fonksiyonun adresini sisteme bildirir.

signal fonksiyonu, iki argüman alır: ilki sinyal numarası, ikincisi sinyal olayını işlemek için kullanılacak fonksiyon. Örnek olarak, aşağıdaki kod satırı SIGINT sinyali gerçekleştiğinde çağrılacak olan "control_c_handler" fonksiyonunu tanımlar:

```c
#include <signal.h>

void control_c_handler(int signum) {
    // do something
}

int main() {
    signal(SIGINT, control_c_handler);
    // do something
    return 0;
}
```

### sigaction()
C dilinde sigaction() fonksiyonu, UNIX ve benzeri işletim sistemlerinde sinyal olaylarını işlemek için kullanılan bir fonksiyondur. Bu fonksiyon, <signal.h> kütüphanesinde tanımlıdır.

Signal ile ayni isi gorur.

### Signal vs Sigaction

- signal() fonksiyonu sinyal isleyici yurutulurken tekrar sinyal alinmasini engellemez fakat, sigaction sinyal isleyici yurutulurken tekrar sinyal alinmasini engeller ve bu reetrancy problemlerinin onune gecer.
- signal()'de portability sorunlari varken, sigaction()'da portability sorunlari yoktur. Portability, farkli isletim sistemlerinde calisabilmek olarak dusunulebilir.

***Reetrancy Nedir?***

Reentrancy sorunu, bir fonksiyonun kendisini tekrar çağırması ya da başka bir fonksiyon tarafından çağırılması sırasında oluşabilecek sorunları ifade eder. Özellikle, fonksiyon çalışmaya devam ederken, başka bir fonksiyon çağrılabilir ve bu ikinci çağrı fonksiyonun çalışmasını etkileyebilir. Bu, programın beklenmedik şekilde çalışmasına veya çökmesine yol açabilir.

Reentrancy sorunları sinyal işlemlerinde de oluşabilir. Örneğin, bir sinyal işlemi sırasında, çağrılan fonksiyon çalışmaya devam ederken, başka bir sinyal işlemi gerçekleşebilir. Bu, sinyal işlemi sırasında çağrılan fonksiyonun beklenmedik şekilde çalışmasına yol açabilir.

### pause()

pause() fonksiyonu, programın çalışmasını askıya alır ve sinyal olayı gerçekleşene kadar bekler. Eğer bir sinyal olayı gerçekleşirse, program çalışmaya devam eder. Bu fonksiyon işlem gerçekleştiğinde sinyal olayı gerçekleştiği için 0 döndürür, eğer işlem gerçekleşmedi ise -1 döndürür.

```c
#include <unistd.h>

int main() {
    // do something
    pause();
    // do something
    return 0;
}
```
### usleep()

C dilinde usleep() fonksiyonu, UNIX ve benzeri işletim sistemlerinde belirli bir zaman aralığı için uyku modunda beklemek için kullanılan bir fonksiyondur. Bu fonksiyon, <unistd.h> kütüphanesinde tanımlıdır.

usleep() fonksiyonu, verilen miktarda mikrosaniye cinsinden bir zaman aralığı için uyku modunda bekler. Örneğin, aşağıdaki kod satırı, programın 1 saniye (1000000 mikrosaniye) boyunca uyku modunda beklemesini sağlar:

```c
#include <unistd.h>

int main() {
    // do something
    usleep(1000000);
    // do something
    return 0;
}
```

# Kullanilan Operatorler

### Binary Kaydirma Operatoru
C dilinde ">>" operatörü bit kaydırma operatörüdür. Bu operatör ile verilen sayının bitleri sağa doğru kaydırılır. Örneğin, "x >> 2" ifadesi x değişkeninin bitlerini 2 pozisyon sağa kaydırır ve x'in yeni değeri elde edilir.

### Binary AND, VE (&) Operatörü 

İki sayının ve’sini alır. Her iki bit 1 olduğu durumlarda 1, farklı olduğu durumlarda ise 0 değerini alır.

