import { Clock } from "@/api/endpoints/clock";
import { ClockData } from "@/types/genericTypes";

function getAverages(clockData: ClockData[]): [string, string, string] {
  let startTotalMinutes = 0;
  let endTotalMinutes = 0;
  let differenceTotalMinutes = 0;

  clockData.forEach((data) => {
    const [startHours, startMinutes] = data.start.split(":").map(Number);
    const [endHours, endMinutes] = data.end.split(":").map(Number);
    const [differenceHours, differenceMinutes] = data.difference.split(":").map(Number);

    startTotalMinutes += startHours * 60 + startMinutes;
    endTotalMinutes += endHours * 60 + endMinutes;
    differenceTotalMinutes += differenceHours * 60 + differenceMinutes;
  });

  const startAverageMinutes = clockData.length ? Math.round(startTotalMinutes / clockData.length) : 0;
  const endAverageMinutes = clockData.length ? Math.round(endTotalMinutes / clockData.length) : 0;
  const differenceAverageMinutes = clockData.length ? Math.round(differenceTotalMinutes / clockData.length) : 0;
  const startAverage = `${Math.floor(startAverageMinutes / 60)
    .toString()
    .padStart(2, "0")}:${(startAverageMinutes % 60).toString().padStart(2, "0")}`;
  const endAverage = `${Math.floor(endAverageMinutes / 60)
    .toString()
    .padStart(2, "0")}:${(endAverageMinutes % 60).toString().padStart(2, "0")}`;
  const differenceAverage = `${Math.floor(differenceAverageMinutes / 60)
    .toString()
    .padStart(2, "0")}:${(differenceAverageMinutes % 60).toString().padStart(2, "0")}`;

  return [startAverage, endAverage, differenceAverage];
}

function addOneHour(timeString: string): string {
  const [hours, minutes] = timeString.split(":").map(Number);
  const totalMinutes = hours * 60 + minutes;
  const newTotalMinutes = totalMinutes + 60; // Adding 1 hour in minutes

  const newHours = Math.floor(newTotalMinutes / 60) % 24; // Modulo 24 to keep it within a day
  const newMinutes = newTotalMinutes % 60;

  return `${newHours.toString().padStart(2, "0")}:${newMinutes.toString().padStart(2, "0")}`;
}

function getTimeDifference(startTime: string, endTime: string) {
  const [startHours, startMinutes] = startTime.split(":").map(Number);
  const [endHours, endMinutes] = endTime.split(":").map(Number);
  const startTotalMinutes = startHours * 60 + startMinutes;
  const endTotalMinutes = endHours * 60 + endMinutes;
  const timeDifference = endTotalMinutes - startTotalMinutes;
  const differenceHours = Math.floor(timeDifference / 60);
  const differenceMinutes = timeDifference % 60;

  return `${differenceHours.toString().padStart(2, "0")}:${differenceMinutes.toString().padStart(2, "0")}`;
}

function formatData(clocks: Clock[]) {
  const result: ClockData[] = [];

  clocks?.forEach((clock) => {
    if (clock.end) {
      const start = addOneHour(clock.start!.match(/\d\d:\d\d/)![0]); //UTC is winter hour - 1
      const end = addOneHour(clock.end!.match(/\d\d:\d\d/)![0]); //UTC is winter hour - 1

      result.push({
        date: clock.start!.split("T")[0],
        start: start,
        end: end,
        difference: getTimeDifference(start, end),
        startAverage: "",
        endAverage: "",
        differenceAverage: "",
      });
    }
  });
  return result;
}

export default function useTransformData() {
  return { getAverages, formatData };
}
