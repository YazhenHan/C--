/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return {
        a: init,
        increment() {
            this.a++;
            return this.a;
        },
        decrement() {
            this.a--;
            return this.a;
        },
        reset() {
            this.a = init;
            return this.a;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */