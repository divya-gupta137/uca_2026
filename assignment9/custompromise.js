function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let handlers = [];

    function resolve(result) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = result;

        handlers.forEach(handler => handler());
    }

    function reject(error) {
        if (state !== "pending") return;

        state = "rejected";
        value = error;

        handlers.forEach(handler => handler());
    }

    function handle(handler) {
        if (state === "pending") {
            handlers.push(() => handle(handler));
            return;
        }

        if (state === "fulfilled") {
            if (!handler.onFulfilled) {
                handler.resolve(value);
                return;
            }

            try {
                const result = handler.onFulfilled(value);

                if (result instanceof NewPromise) {
                    result.then(handler.resolve).catch(handler.reject);
                } else {
                    handler.resolve(result);
                }
            } catch (error) {
                handler.reject(error);
            }
        }

        if (state === "rejected") {
            if (!handler.onRejected) {
                handler.reject(value);
                return;
            }

            try {
                const result = handler.onRejected(value);
                handler.resolve(result);
            } catch (error) {
                handler.reject(error);
            }
        }
    }

    this.then = function (onFulfilled, onRejected) {
        return new NewPromise((resolve, reject) => {
            handle({
                onFulfilled,
                onRejected,
                resolve,
                reject
            });
        });
    };

    this.catch = function (onRejected) {
        return this.then(null, onRejected);
    };

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}

new NewPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});
