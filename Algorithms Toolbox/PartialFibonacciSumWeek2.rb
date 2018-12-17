def fib(n)
    a, b = 0, 1
    (n-1).times do
        a, b = b, (a + b) % 10
    end
    b
end

def fib_partial_sum(m, n)
    if n == m
        fib(m % 60)
    else
        m = m % 60
        n = n % 60

        m = fib(m + 1) - 1
        n = fib(n + 2) - 1

        (n - m) % 10
    end
end

if __FILE__ == $0
    m, n = gets.split().map(&:to_i)
    puts "#{fib_partial_sum(m, n)}"
end
