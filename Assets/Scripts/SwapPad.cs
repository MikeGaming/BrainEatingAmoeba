﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SwapPad : MonoBehaviour
{

    [SerializeField] string[] padText1 = new string[6];
    [SerializeField] string[] padText2 = new string[6];
    [SerializeField] string[] padText3 = new string[6];
    string[] currentPadText;

    [SerializeField] Text[] padTexts = new Text[6];

    int padIndex = 0;

    private void Start()
    {
        currentPadText = padText1;
        for (int i = 0; i < padTexts.Length; i++)
        {
            padTexts[i].text = currentPadText[i];
        }
    }

    public void SwapPads()
    {
        padIndex++;
        if (padIndex >= 3) padIndex = 0;
        switch (padIndex)
        {
            case 0:
                currentPadText = padText1;
                break;

            case 1:
                currentPadText = padText2;
                break;
            
            case 2:
                currentPadText = padText3;
                break;

        }
        for (int i = 0; i < padTexts.Length; i++)
        {
            padTexts[i].text = currentPadText[i];
        }
    }

}