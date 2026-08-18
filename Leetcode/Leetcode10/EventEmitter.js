class EventEmitter {
    constructor() {
        this.map = new Map();
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.map.has(eventName)) {
            this.map.set(eventName, new Set());
        }
        this.map.get(eventName).add(callback);
        return {
            unsubscribe: () => {
                this.map.get(eventName).delete(callback);
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const ans = [];
        if (this.map.has(eventName))
        for (const element of this.map.get(eventName)) {
            ans.push(element(...args));
        }
        return ans;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */