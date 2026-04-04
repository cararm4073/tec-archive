%Change the input parameters here
func = @(x) 2*x^3 + x^2 -x + 1;
derivative = @(x) 6*x^2 +2*x -1;
maxIters = 6;
initialGuess = -1,2;

example = findRoots(func, derivative, maxIters, initialGuess);
%start of the function
function root = findRoots(func, derivative, maxIters, initialGuess, minError)
    %This function uses the Newton-Raphson method to find the roots of a given (by the user, above) function. It iteratively approximates the root using the formula of this method
    %The function also generates a graph showing each iteration's (try) tangent line.

    %inputs:
    % func         - handles the function f(x)
    % derivative   - handles the derivative of the function, f'(x)
    % maxIters     - how many iterations (tries) are allowed
    % minError     - optional. Minimum acceptable error for input (default: 0.1)
    % initialGuess - optional. starting point for iterations (default and recommended: 0)

    %outputs
    % root - the approximated root of the function
    %the graph is also shown, but is not part of the outputs from the user defined function
    
    %more in depth documentation: *redacted (available on the repo)*
    %*redacted*

    %Handle initial guess, which should always be 0
    if nargin < 4
        initialGuess = 0;
    end

    %Handle minError input
    if nargin < 5
        minError = 0.1;
    end

    %Start the variables with the first input from the user
    currentGuess = initialGuess;
    currentIter = 0; %counter on which iteration we are
    
    guesses = [currentGuess]; %store each iteration for later use
    
    %Prepare figure for graphing
    figure('Color', 'white');
    
    fprintf('\n========== NEWTON-RAPHSON METHOD ==========\n');
    fprintf('Starting point: x = %.6f\n', currentGuess);
    fprintf('You have this many iterations: %d\n', maxIters);
    fprintf('\n')
    
    %Iterations process (newton-raphson method)
    while currentIter < maxIters %While the current iteration doesn't exceed the max iterations stablised
        
        %Ask for the iterations
        fprintf('\n   Iteration %d/%d   \n', currentIter + 1, maxIters);
        fprintf('Attempts remaining: %d\n', maxIters - currentIter);
        if currentIter > 0
            fprintf('Error from previous iteration: %.3f\n', iterationError);
        end
        nextGuess = input('Enter your guess for x: ');

        %evaluate for each iteration using the NEW guess
        fx = func(nextGuess);           % Evaluate f(x) at nextGuess
        dfx = derivative(nextGuess);    % Evaluate f'(x) at nextGuess
        
        %manage if derivative is 0
        if dfx == 0 
            error('Derivative is zero. Code is closing')
        end %else the code continues
        
        iterationError = abs(nextGuess - currentGuess); % Calculate the error from the input

        %feedback, does it need to be bigger or smaller?
        if abs(fx) < 0.001
            direction_hint = 'Very close to the root!';
        elseif fx > 0 && dfx > 0  
            direction_hint = 'Next guess should be SMALLER';
        elseif fx > 0 && dfx < 0 
            direction_hint = 'Next guess should be BIGGER';
        elseif fx < 0 && dfx > 0 
            direction_hint = 'Next guess should be BIGGER';
        elseif fx < 0 && dfx < 0
            direction_hint = 'Next guess should be SMALLER';
        else % f(x) = 0 or f'(x) = 0
            direction_hint = 'Close!';
        end

        %display results
        fprintf('\nYour result:\n');
        fprintf('You should get closer to a 0!\n')
        fprintf('f(x): %.6f\n', fx);
        fprintf('Feedback: %s\n', direction_hint);
        fprintf('-------------------\n');
        
        guesses = [guesses, nextGuess]; %add the new guess to the array

        %Graphing for every iteration
        clf; %clear the figure to update it after every iteration
        
        %limits based on the iterations
        xMin = min(guesses);
        xMax = max(guesses);
        xMargin = (xMax - xMin) * 0.2;
        if xMargin == 0, xMargin = 1; end %avoid zero margin
        xLimits = [xMin - xMargin, xMax + xMargin];
        
        %plotting the function
        x = linspace(xLimits(1), xLimits(2), 500);
        plot(x, arrayfun(func, x), 'b-', 'LineWidth', 2);
        hold on;
        plot(x, zeros(size(x)), 'k--', 'LineWidth', 0.5);
        
        %plotting tangent lines from all iterations
        for j = 1:(length(guesses) - 1)
            x = linspace(guesses(j) - 1.5, guesses(j) + 1.5, 100);
            plot(x, derivative(guesses(j)) * (x - guesses(j)) + func(guesses(j)), '--', 'LineWidth', 1.5);
            plot(guesses(j), func(guesses(j)), 'o', 'MarkerSize', 8, 'LineWidth', 2);
            plot(guesses(j+1), 0, 'x', 'MarkerSize', 10, 'LineWidth', 2);
        end
        
        %axis limits getting values from the function
        xlim(xLimits);
        yVals = arrayfun(func, linspace(xLimits(1), xLimits(2), 100));
        yMargin = (max(yVals) - min(yVals)) * 0.1;
        if yMargin == 0, yMargin = 1; end %avoid zero margin for weird visuals
        ylim([min(yVals) - yMargin, max(yVals) + yMargin]);
        
        %graph settings
        grid on;
        title('*redacted* | Newton-Raphson Method');
        xlabel('x');
        ylabel('f(x)');
        legend('f(x)', 'y = 0', 'Location', 'best');
        hold off;
        drawnow; %force to update the figure

        %If the calculated error from the input is inside the acceptable limit, the code stops as the root was found
        if iterationError < minError
            currentGuess = nextGuess; %update to final value before breaking
            fprintf('Root found! Error respect to the real root is less than %.f\n\n', minError);
            break;
        else
            currentGuess = nextGuess;
            currentIter = currentIter + 1;
        end %end for if section    
    end %end for while loop


    %Either if the root was guessed, or max iters were reached
    root = currentGuess;
    fprintf('Estimated root by you: %.3f\n', nextGuess); %last guessed root
    fprintf('Root found by Newton-Raphson: %.6f\n', root); %true root from the method
    fprintf('Total tries: %d\n', currentIter +1);
    fprintf('-- -- -- -- -- -- -- -- -- -- -- --\n\n');

    %Final graph
    clf; %clear figure to show final plot

    %limits from the iterations
    xMin = min(guesses);
    xMax = max(guesses);
    xMargin = (xMax - xMin) * 0.2;  % 20% margin 
    if xMargin == 0, xMargin = 1; end
    xLimits = [xMin - xMargin, xMax + xMargin];

    %plot the function
    x = linspace(xLimits(1), xLimits(2), 500);
    y = arrayfun(func, x);

    plot(x, y, 'b-', 'LineWidth', 2);
    hold on;
    plot(x, zeros(size(x)), 'k--', 'LineWidth', 0.5);  

    %tangent lines for every try
    for i = 1:(length(guesses) - 1)
        x = linspace(guesses(i) - 1.5, guesses(i) + 1.5, 100);
        plot(x, derivative(guesses(i)) * (x - guesses(i)) + func(guesses(i)), '--', 'LineWidth', 1.5);
        plot(guesses(i), func(guesses(i)), 'o', 'MarkerSize', 8, 'LineWidth', 2);
        plot(guesses(i+1), 0, 'x', 'MarkerSize', 10, 'LineWidth', 2);
    end

    %final root in the same graph with a red star
    plot(root, func(root), 'r*', 'MarkerSize', 15, 'LineWidth', 2);

    %Settings, limits of the graph
    xlim(xLimits);
    
    yVals = arrayfun(func, linspace(xLimits(1), xLimits(2), 100));
    yMargin = (max(yVals) - min(yVals)) * 0.1;
    if yMargin == 0, yMargin = 1; 
    end
    ylim([min(yVals) - yMargin, max(yVals) + yMargin]);

    %Settings of the graph
    grid on;
    title('*redacted* | Newton-Raphson Method');
    xlabel('x');
    ylabel('f(x)');
    legend('f(x)', 'y = 0', 'Root', 'Location', 'best');
    hold off;

end %of the whole function
