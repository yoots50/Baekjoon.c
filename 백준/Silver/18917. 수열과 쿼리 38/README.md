# [Silver III] 수열과 쿼리 38 - 18917 

[문제 링크](https://www.acmicpc.net/problem/18917) 

### 성능 요약

메모리: 1124 KB, 시간: 268 ms

### 분류

구현(implementation), 수학(math)

### 문제 설명

<p>처음에 0이 하나 포함되어있는 배열 A가 있다. 이때, 다음 쿼리를 수행해야 한다.</p>

<ul>
	<li><code>1 x</code>: A의 가장 뒤에 <code>x</code>를 추가한다.</li>
	<li><code>2 x</code>: A에서 <code>x</code>를 제거한다. A에 <code>x</code>가 두 개 이상 있는 경우에는 가장 앞에 있는 하나만 제거한다. 항상 A에 <code>x</code>가 있는 쿼리만 주어진다.</li>
	<li><code>3</code>: A에 포함된 모든 원소를 더한 값을 출력한다.</li>
	<li><code>4</code>: A에 포함된 모든 원소를 XOR한 값을 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에는 쿼리의 개수 M이 주어진다. 둘째 줄부터 다음 M 개의 줄에 쿼리가 주어진다.</p>

### 출력 

 <p>3번 혹은 4번 쿼리가 등장할 때마다, 답을 한 줄에 하나씩 출력한다.</p>

