class System:
    @staticmethod
    def delayMs(self, time: int): ...


class Display:
    @staticmethod
    def setBrightness(self, val: int): ...

    @staticmethod
    def getBrightness(self) -> int: ...


class Clock:
    @staticmethod
    def getHours(self) -> int: ...

    @staticmethod
    def getMinutes(self) -> int: ...

    @staticmethod
    def getSeconds(self) -> int: ...

    @staticmethod
    def getYear(self) -> int: ...

    @staticmethod
    def getMonth(self) -> int: ...

    @staticmethod
    def getDay(self) -> int: ...

    @staticmethod
    def getWeekDay(self) -> int: ...

