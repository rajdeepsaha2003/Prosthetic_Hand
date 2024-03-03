% Generate the signal composed of sinusoids at specified frequencies
fs = 500.0; % Sampling rate in Hz
t = linspace(0, 2, fs); % 2 seconds
frequencies = [45, 60, 100, 160]; % Frequencies in Hz
sig = sum(sin(2*pi*frequencies.'*t), 1);

% Plot the original signal
figure;

plot(t, sig);
title('Raw EMG Signal with Multiple Frequencies');
xlabel('Time [seconds]');
ylabel('Amplitude');
grid on;

% Design the bandpass filter
[b, a] = butter(4, [74.5, 149.5] / (fs / 2), 'bandpass');
[sos, g] = tf2sos(b, a);

% Apply the bandpass filter
filtered_sig = sosfilt(sos, sig);

% Plot the frequency response of the filter
figure;
freqz(sos, 1024, fs);
title('Bandpass Filter Frequency Response');
xlabel('Frequency (Hz)');
ylabel('Gain (dB)');
grid on;

% Add -3 dB cutoff point
cutoff_freq = [74.5, 149.5];
cutoff_response = -3 * ones(size(cutoff_freq));
hold on;
plot(cutoff_freq, cutoff_response, 'ro');
text(cutoff_freq(1), -3, '(-3 dB)', 'VerticalAlignment', 'bottom');

% Add vertical lines penetrating the x-axis
plot([cutoff_freq(1), cutoff_freq(1)], ylim, 'k--');
plot([cutoff_freq(2), cutoff_freq(2)], ylim, 'k--');

hold off;

% Plot the signal after applying the bandpass filter
figure;
plot(t, filtered_sig);
title('EMG Signal After Bandpass Filtering');
xlabel('Time [seconds]');
ylabel('Amplitude');
grid on;
