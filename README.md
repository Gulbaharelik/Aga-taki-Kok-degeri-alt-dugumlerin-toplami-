# Agactaki-Kok-degeri-alt-dugumlerin-toplami-
Kısa Sınav 2 : 2. Soru

Buradaki belirttiğim üst başlığa göre şu soru üzeinden ilericez;

Tam olarak 3 düğümden oluşan ikili bir ağacın kökü verildiğinde, bu değerin alt düğümlerin(child) toplamı olup olmadığını bulunuz.
Burada struct'lar ve özyineleme gibi belirli işlemler kullanılacak.

İlk olarak agaç düğümünü ,düğüm oluşturmayı ve ağaç oluşturmayı struct yapılarıyla gösterceğiz.
Ağaç düğümü struct'ı bizden istenen sol ve sağ düğümlerinin içerir.
Ağaç düğümü üzerinden düğüm oluşturma struct'ı ise yeni düğümleri ve bu düğümleri içirir ve bu yeni düğümler ilk olarak boştur çünkü biz daha kullanıcıdan değer almadık. Ayriyeten burada yeni düğümler için burada yer de ayrılır.

Ağaç oluşturmak için de farklı bir struct fonksiyonu yapısı kullanılır bu yapının içerisinde kök değeri,sol çocuğun değeri ve sağ çocuğun değeri kullanıcıdan istenir ama bu bir fonksiyon olduğu için bu fonksiyon çağrılmadan bu değer kullanıcıdan istenemez.
Bu değerler istenirken değer olmama durumları düşünülür.

En son olarak ana fonksiyon açılır ve burada yukarıda bahsettiğim struct fonksiyon yapıları tek tek sırasıyla çağrılır.
Ve bu çağrılan fonksiyonlara göre kök değerin sol ve sağ çocukların toplamına eşit olup olmadığı ekranda gösterilir.
