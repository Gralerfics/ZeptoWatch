class IMU:
    def initialize(self):
        pass

    def getTemperature(self) -> int:
        pass

    def getGyroscope(self) -> list:
        pass

    def getAccelerometer(self) -> list:
        pass


class Battery:
    def isCharging(self) -> int:
        pass

    def getRawData(self) -> int:
        pass


class Microphone:
    def startSampling(self):
        pass

    def stopSampling(self):
        pass

    def getRawData(self) -> int:
        pass


class Vibrator:
    def vibrate(self, ms: int, pulse: int):
        pass

    def stop(self):
        pass

