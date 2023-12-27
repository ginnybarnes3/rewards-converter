public class RewardValue{
    double cash;
    int miles;

    public RewardValue(double cashValue) {
        cash = cashValue;
        miles = (int)Math.round(cashValue/0.0035); // miles needs to be an integer, so rounding up and converting to int here
    }

    public RewardValue(int milesValue) {
        miles = milesValue;
        cash = milesValue * 0.0035;
    }
    public double getCashValue() {
        return cash;
    }

    public double getMilesValue() {
        return miles;
    }

}
