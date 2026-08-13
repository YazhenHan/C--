type F = (x: number) => number;

function compose(functions: F[]): F {
    
	return function(x) {
        for (let i = 0; i < functions.length; i++) {
            x = functions[functions.length - 1 - i](x);
        }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */