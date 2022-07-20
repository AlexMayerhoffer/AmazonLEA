# AmazonLEA
Amazon SDA challenge

![alt text](https://edu.tuiasi.ro/pluginfile.php/113873/mod_label/intro/Premiile%20LearnEarn_SDA2022.jpg)

Problema 1 <br/>
Se citesc de la tastatura N elemente numere intregi care se stocheaza si reprezinta intr-o structura de
date SD. Propuneti doi algoritmi eficienti care determina al k-lea cel mai mic element si al k-lea cel
mai mare element din multimea data, fara sa se utilizeze memorie suplimentara (in afara de cea
ocupata de SD) si fara sa se numere elementele.

Problema 2 <br/>
Fie 𝑇𝑇 un şir de 𝑛𝑛 caractere şi 𝑃𝑃 un pattern de 𝑚𝑚 caractere. Să se verifice dacă 𝑃𝑃 apare sau nu ca
subsecvenţă în şirul 𝑇𝑇.
Se va parcurge șirul T, caracter cu caracter, și, pentru fiecare poziție i se va verifica potrivirea șirului
P cu șirul 𝑇𝑇[𝑖𝑖…𝑖𝑖+𝑚𝑚−1] folosind metoda descrisă în continuare (nu prin verificarea egalității caracter
cu caracter).
Fie 𝑏𝑏 numărul de caractere distincte care apar în 𝑇𝑇 (acest număr b reprezintă cardinalul alfabetului
folosit).
Un şir de lungime 𝑚𝑚 poate fi considerat un număr în baza 𝑏𝑏+1 având 𝑚𝑚 cifre (se folosesc cifre de la
1 la 𝑏𝑏).
Se asociază pattern-ului 𝑃𝑃 o valoare 𝑝𝑝 (şirul de caractere este considerat ca un număr întreg în baza
𝑏𝑏+1).
Pentru fiecare secvenţă de 𝑚𝑚 caractere din şirul 𝑇𝑇 se calculează 𝑡𝑡i, valoarea în baza 𝑏𝑏+1 a subsecvenţei
din 𝑇𝑇 care începe la poziţia 𝑖𝑖 (𝑇𝑇[𝑖𝑖…𝑖𝑖+𝑚𝑚−1]). Evident, 𝑝𝑝=𝑡𝑡𝑖𝑖 dacă şi numai dacă 𝑇𝑇[𝑖𝑖…𝑖𝑖+𝑚𝑚−1].
Valorile 𝑡𝑡𝑖𝑖 pentru i=1,… 𝑖𝑖+𝑚𝑚−1 se pot calcula recurent astfel:
𝑡𝑡𝑖𝑖+1= (𝑏𝑏+1) ∗ (𝑡𝑡𝑖𝑖− (𝑏𝑏 + 1) 𝑚𝑚−1∗𝑇𝑇[𝑖𝑖]) +𝑇𝑇 [𝑖𝑖+𝑚𝑚].
Dificultatea constă în faptul că 𝑝𝑝 şi 𝑡𝑡𝑖𝑖 pot fi numere foarte mari. Prin urmare, operaţiile cu aceste
numere nu se execută în timp constant.
Se va lucra cu 𝑝𝑝 şi 𝑡𝑡i mod 𝑄𝑄, unde 𝑄𝑄 este un număr prim convenabil ales, mai exact se foloseşte o
funcţie de dispersie. Deoarece 𝑝𝑝 𝑚𝑚𝑚𝑚𝑚𝑚 𝑄𝑄= 𝑡𝑡𝑖𝑖 𝑚𝑚𝑚𝑚𝑚𝑚 𝑄𝑄 nu implică faptul că 𝑝𝑝=𝑡𝑡𝑖𝑖, și cu atât mai puțin că
𝑃𝑃=𝑇𝑇[𝑖𝑖…𝑖𝑖+𝑚𝑚−1], apar coliziuni. Dar dacă 𝑝𝑝 𝑚𝑚𝑚𝑚𝑚𝑚 𝑄𝑄≠𝑡𝑡𝑖𝑖 𝑚𝑚𝑚𝑚𝑚𝑚 𝑄𝑄, atunci sigur 𝑃𝑃≠𝑇𝑇[𝑖𝑖…𝑖𝑖+𝑚𝑚−1].
Aşadar, acest algoritm este probabilistic, eficienţa în detectarea potrivirii pattern-ului depinde de
funcţia de dispersie. Pentru a elimina potrivirile “false”, se va aplica o verificare caracter cu caracter
pentru fiecare potrivire detectată. Alternativ, se pot folosi mai multe funcţii de dispersie.
