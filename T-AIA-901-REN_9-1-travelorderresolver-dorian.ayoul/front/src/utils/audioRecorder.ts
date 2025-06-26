// src/utils/audioRecorder.ts
export const startRecording = async (): Promise<Blob> => {
    const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
    const mediaRecorder = new MediaRecorder(stream, { mimeType: 'audio/webm' });
    const audioChunks: Blob[] = [];

    return new Promise((resolve, reject) => {
        mediaRecorder.ondataavailable = (event) => audioChunks.push(event.data);
        mediaRecorder.onstop = () => resolve(new Blob(audioChunks, { type: 'audio/webm' }));

        mediaRecorder.onerror = (event: Event) => {
            const error = (event as ErrorEvent).error;
            reject(error || 'Recording failed');
        };

        mediaRecorder.start();

        setTimeout(() => {
            mediaRecorder.stop();
        }, 5000);
    });
};

