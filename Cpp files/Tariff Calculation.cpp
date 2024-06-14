double energyCost(double Energy)
{
    double energy = Energy ;
    double cost;
        if (energy > 1000)
        {
            cost = energy * 1.65;
        }
        else if (energy > 650)
        {
            cost = energy * 1.5;
        }
        else if (energy > 350)
        {
            cost = 200 * 0.83 + 150 * 1.25 + (energy - 350) * 1.4;
        }
        else if (energy > 200)
        {
            cost = 200 * 0.83 + (energy - 200) * 1.25;
        }
        else if (energy> 100)
        {
            cost = energy * 0.83;
        }
        else if (energy > 50)
        {
            cost = 50 * .58 + (energy - 50) * .68;
        }
        else if (energy > 0)
        {
            cost = energy * .58;
        }
    return cost;
}
